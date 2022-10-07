%%
T = 0; % Tempo
N = 4; % Numero da matricula
num = 500*N;
den = conv([1 0], conv([1 3+N], [1 25/sqrt(N)]));
g_planta = tf(num, den, 'InputDelay', T);

figure();
margin(g_planta);
createGraph(g_planta, {'g_planta com atraso de 0.01'});

%%
% Dado a Gma, podemos achar os pontos correspondentes no gráfico de bode
[mag,phase,wout] = bode(g_planta);
mag = squeeze(mag);
phase = squeeze(phase);

new_phase = 30 - 180;

%value_freq = interp1(20*log10(mag), wout, 9.5370); 
% Valor da frequencia a partir da fase
value_freq = interp1(phase, wout, new_phase); 

% Valor da fase a partir da frequencia
value_phase = interp1(wout, phase, value_freq); 

% Valor do ganho a partir da frequencia
value_mag = interp1(wout, 20*log10(mag), value_freq);

fprintf('Para %d° ---> Fase: %f, Magnitude: %f, Frequencia: %f\n', new_phase, value_phase, value_mag, value_freq);

%%
% Novo gráfico de Bode com nova margem de fase e ganho
% Convertendo o valor da magnitude que estava em dB

syms kpi
eq = 20*log10(kpi) + value_mag;
kpi = double(solve(eq));

% Nova g_planta com o kpi, que é controlador proporcional
gma = g_planta*kpi; 
[MGgma, MFgma, wGgma, wFgma] = margin(gma);%retorno do margin
fprintf('\nValores da nova planta com o Kpi:\n');
fprintf('MG: %f, MF: %f, wG: %f, wF: %f\n\n', MGgma, MFgma, wGgma, wFgma);

createGraph(gma, {'Gma com Kpi'})

%%
% Grafico com a Gma original e a outra com o Kpi na mesma imagem
createGraph([g_planta, gma], {'g_planta', 'gma'});

%%

% Projetando o controlador PI
kii_array = []; % Possiveis valores de ki para o controlador PI
gmf_pi_array = []; % Possiveis novas plantas com o controlador PI
for i = [3 5 9 10 12 14 16 18 20]
    result_kii = kpi*wFgma/i;
    kii_array = [kii_array,result_kii];

    result_pi = tf([kpi result_kii], [1 0]);
    result_gma = g_planta*result_pi;
    
    result_gmf = feedback(result_gma,1);
    gmf_pi_array = [gmf_pi_array, result_gmf];
end

%%
% Cria uma tabela para os valores dos possiveis gmf com o Kii
% Tabela 1
Tabela1 = createTabela(gmf_pi_array, kii_array, {'Sobressinal (%)','T. Subida (s)', 'T. Estabelecimento(s)', 'Kii'});

%%
% Fazer para o controlador PD com o PI, ou seja PID
kdd_array = [];
gmf_pid_array = [];

for i = [1.1 1.15 1.2 1.25]
    result_kdd = i/wFgma;
    kdd_array = [kdd_array, result_kdd];
end

%% 
% Interecao bolada que vai encontrar o melhor projeto
kii_indice = 1;
kdd_indice = 1;
melhor_MF_pid = 90;
melhores_kdd = [];
melhores_kii = [];
melhor_kii = 0;
melhor_kdd = 0;

gmf_pid_array = [];

for kii = kii_array
    for kdd = kdd_array
        % Controlador PID
        n_pid_final = conv([kpi kii_array(kii_indice)], [kdd_array(kdd_indice) 1]);
        d_pid_final = [1 0];
        pid_final = tf(n_pid_final, d_pid_final);
        
        % Nova planta com o controlador PID
        result_gma_pid = g_planta * pid_final;
        
        % Novos valores de margem para o controlador PID final
        [MG_pid, MF_pid, wG_pid, wF_pid] = margin(result_gma_pid);

        if(MF_pid >= 60)
            fprintf('MF: %f, Kii: %f - (%d), Kdd: %f - (%d)\n',MF_pid, kii, kii_indice, kdd, kdd_indice);
            if MF_pid < melhor_MF_pid
                melhor_MF_pid = MF_pid;
                melhor_kii = kii;
                melhor_kdd = kdd;
                melhor_gma_pid = result_gma_pid; % Salva o melhor resultado (mais proximo de 60)
            end 

            result_gmf = feedback(result_gma_pid,1);
            gmf_pid_array = [gmf_pid_array, result_gmf]; % Array com todos as possiveis plantas com o controlador PID
            melhores_kdd = [melhores_kdd, kdd];
            melhores_kii = [melhores_kii, kii];
        end
        kdd_indice = kdd_indice + 1;
    end
    kii_indice = kii_indice + 1;
    kdd_indice = 1;
end

fprintf('\n\nVENCEDOR:\n');
fprintf('MF: %f, Kii: %f, Kdd: %f\n',melhor_MF_pid, melhor_kii, melhor_kdd);

%%
% Tabela 2 com os valores de Kii e Kdd
Tabela2 = createTabelaFull(gmf_pid_array,melhores_kii,melhores_kdd, {'Sobressinal (%)','T. Subida (s)', 'T. Estabelecimento(s)', 'Kii', 'Kdd'});

%%
% O melhor de todos!
% Novos valores de margem para o controlador PID final
[MG_pid2, MF_pid2, wG_pid2, wF_pid2] = margin(melhor_gma_pid);

gmf_pid_final = feedback(melhor_gma_pid,1);
createGraph(melhor_gma_pid, 'Planta final');

% o que seria isso?
% t=0.0:0.01:7;
% y5 = step(gmf_pid_final,t);
% stepinfo(y5,t);

%%
% Figura com a planta original e com PID
createGraph([g_planta, melhor_gma_pid], {'Planta original', 'Planta com PID'});


%%
% Funcao que gera os graficos (parametro1: array de g_planta, parametro2:
% objeto de legenda para cada planta
function createGraph(plantas, legends)
    figure();
    bode(plantas);
    indice = 1;
    for i = plantas
        bode(plantas(indice));
        indice = indice + 1;
        hold on;
    end
    legend(legends);
    hold off;
end

%%
% Funcao que gera as tabelas individuais
function tabela = createTabela(g_array, controlador_array, coluna)
    col_pid = [];
    index = 1;
    for i = g_array
        OS_pid=0;
        RT_pid=0;
        ST_pid=0;
        st_info=stepinfo(i);
        OS_pid(index)=st_info.Overshoot;
        RT_pid(index)=st_info.RiseTime;
        ST_pid(index)=st_info.SettlingTime;
    
        col_pid = [col_pid, [OS_pid(index) RT_pid(index) ST_pid(index) controlador_array(index)]'];
        index = index+1;
    end
    tabela = table(col_pid,'RowNames',coluna);
end

%%
% Full tabela
% Funcao que gera as tabelas
function tabela = createTabelaFull(g_array, array_kdd, array_kii, coluna)
    col_pid = [];
    index = 1;
    for i = g_array
        OS_pid=0;
        RT_pid=0;
        ST_pid=0;
        st_info=stepinfo(i);
        OS_pid(index)=st_info.Overshoot;
        RT_pid(index)=st_info.RiseTime;
        ST_pid(index)=st_info.SettlingTime;
    
        col_pid = [col_pid, [OS_pid(index) RT_pid(index) ST_pid(index) array_kii(index) array_kdd(index)]'];
        index = index+1;
    end
    tabela = table(col_pid,'RowNames',coluna);
end


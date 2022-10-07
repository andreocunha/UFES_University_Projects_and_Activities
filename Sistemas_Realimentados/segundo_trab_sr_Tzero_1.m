%%
T = 0; % Tempo
N = 4; % Numero da matricula
n_planta = 500*N;
d1_planta = [1 0];
d2_planta = [1 3+N];
d3_planta = [1 25/sqrt(N)];
d12 = conv(d1_planta,d2_planta);
d_planta = conv(d12,d3_planta);
g_planta = tf(n_planta, d_planta, 'InputDelay', T);

margin(g_planta); % Mostra o grafico de bode com a margem de fase e ganho

%%
% Novo gráfico de Bode com nova margem de fase e ganho

% Para isso a nova fase para projetar o controlador PID em -155 graus (NovaFase = 25 - 180)
% Para essa fase, analizar a nova frequencia de corte
% Para uma fase de -155, w =5,8 e com 5,8 o ganho vale 8.83 db  (Esses valores foram obtidos a partir do grafo de bode)

% Convertendo o valor que estava em dB na frequencia de corte em rad/s
syms kpi
eq = 20*log10(kpi) + 8.83; % Trocar o valor de 8.83 por o valor que encontrar no grafico de ganho
kpi = double(solve(eq));

% Nova g_planta com o kpi, que é controlador proporcional
gma = g_planta*kpi; 
[MGgma, MFgma, wGgma, wFgma] = margin(gma);%retorno do margin

% Novos valores para as margens
MGgma 
MFgma
wGgma
wFgma

margin(gma); % Mostra o grafico de bode com a margem de fase e ganho

%%

% Projetando o controlador PI
kii_array = []; % Possiveis valores de ki para o controlador PI
gmf_pi_array = []; % Possiveis novas plantas com o controlador PI
for i = [2 3 5 7 9 10 12 14 16 18 20]
    result_kii = kpi*wFgma/i;
    kii_array = [kii_array,result_kii];

    result_pi = tf([kpi result_kii], [1 0]);
    result_gma = g_planta*result_pi;
    
    result_gmf = feedback(result_gma,1);
    gmf_pi_array = [gmf_pi_array, result_gmf];
end

%%
% gera a tabela para os valores de KII na planta
index = 1; % Contador para a tabela
col_pi = [];
    
for i = gmf_pi_array
    OS_pi=0;
    RT_pi=0;
    ST_pi=0;
   
    st_info=stepinfo(i);
    OS_pi(index)=st_info.Overshoot; % MP
    RT_pi(index)=st_info.RiseTime; % Tr
    ST_pi(index)=st_info.SettlingTime; % Ts

    col_pi = [col_pi, [OS_pi(index) RT_pi(index) ST_pi(index) kii_array(index) ]'];
    index = index+1;
end
    
Tabela1=table(col_pi,'RowNames',{'Sobressinal (%)','T. Subida (s)', 'T. Estabelecimento(s)','KII' });
% Analisar valores da tabela1 para verificar qual o melhor valor de KII
% kii_array = [valor1, valor2, valor3 ...]
% valor1 ta na posição 1 do array
% Escolher o valor de KII(posicao da tabela) [as posicoes comecam em 1]


%%
% Fazer para o controlador PD com o PI, ou seja PID
kdd_array = [];
gmf_pid_array = [];

for i = [1 1.1 1.2 1.3 1.4 1.5 1.6 1.7 2 2.5 3]
    result_kdd = i/wFgma;
    kdd_array = [kdd_array, result_kdd];

    % Controlador PID
    n_pid = conv([kpi kii_array(7)], [result_kdd 1]);
    d_pid = [1 0];
    result_pid = tf(n_pid, d_pid);

    % Nova planta com o controlador PID
    result_gma_pid = g_planta*result_pid;

    result_gmf = feedback(result_gma_pid,1);
    gmf_pid_array = [gmf_pid_array, result_gmf]; % Array com todos as possiveis plantas com o controlador PID
end

%%
% Tabela 2
% Gera a tabela para os valores de KDD na planta
% Escolher o melhor valor de KDD

col_pid = [];
index = 1;
for i = gmf_pid_array
    OS_pid=0;
    RT_pid=0;
    ST_pid=0;
    st_info=stepinfo(i);
    OS_pid(index)=st_info.Overshoot;
    RT_pid(index)=st_info.RiseTime;
    ST_pid(index)=st_info.SettlingTime;

    col_pid = [col_pid, [OS_pid(index) RT_pid(index) ST_pid(index) kdd_array(index)]'];
    index = index+1;
end
Tabela2=table(col_pid,'RowNames',{'Sobressinal (%)','T. Subida (s)', 'T. Estabelecimento(s)', 'KDD'});
% Analisar valores da tabela2 para verificar qual o melhor valor de KDD

%%
% Achar a gma com o melhor PID encontrado

n_pid_final = conv([kpi kii_array(8)], [kdd_array(5) 1]);
d_pid_final = [1 0];
pid_final = tf(n_pid_final, d_pid_final);

gma_pid_final = g_planta * pid_final;

% Novos valores de margem para o controlador PID final
[MG_pid2, MF_pid2, wG_pid2, wF_pid2] = margin(gma_pid_final);

gmf_pid_final = feedback(gma_pid_final,1);

margin(gma_pid_final);
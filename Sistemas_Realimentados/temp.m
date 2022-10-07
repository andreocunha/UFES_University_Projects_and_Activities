%%
syms s
T = 0; % Tempo
N = 4; % Numero do grupo
num = 500*N;
den = conv([1 0], conv([1 3+N], [1 25/sqrt(N)]));
g_planta = tf(num, den, 'InputDelay', T);
margin(g_planta)


%% Calculo erro em regime

nps = poly2sym(conv(num,[1 0]),s);
dps = poly2sym(den,s);
gps = nps/dps;
 % Entrada rampa
sEs = 1/(gps);
ess = double(limit(sEs,s,0,'right'));
ess
 % Disturbio rampa
sEd = gps/(gps);
essd = double(limit(sEd,s,0,'right'));
essd
% É possível escolher k1 > 1 então
%----------------------------------------------------------------------------------------------% 20*log(Kp) pelo gráfico de bode vale 30.8 dB.

%% Verificando o erro a rampa
k1 = 2;
sEs = 1/(k1*gps);
ess = double(limit(sEs,s,0,'right'));
ess
%erro encontrado 0.02

% Disturbio rampa
sEd = gps/(k1*gps);
essd = double(limit(sEd,s,0,'right'));
essd
%erro encontrado 0.500


%% Projetar o controlador de atraso de Fase
%Gm Margem de ganho
%Pm Fase de Margem
%Wgm Frequencia de cruzamento de ganho
%Wpm Frequencia de cruzamento de fase

[Gm,Pm,Wgm,Wpm]=margin(k1*g_planta);
fprintf('Margem de fase: %f, Largura de banda: %f\n', Pm, Wpm)



%% Passo 3 - Fazer o projeto do atraso com a nova Fase
% FaseGP = 30 - 180 = -150

[mag,phase,wout] = bode(k1*g_planta);
mag = squeeze(mag);
phase = squeeze(phase);
nova_fase = 35 - 180;

% Valor da frequencia a partir da nova fase
freq = interp1(phase, wout, nova_fase); 
freq

% Valor do ganho a partir da frequencia
mod = interp1(wout, 20*log10(mag), freq);
mod

figure()
bode(k1*g_planta);

%w = 5.25
%mod = 16.1 db
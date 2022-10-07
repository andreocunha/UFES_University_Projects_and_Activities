% Andre Oliveira Cunha - Lista 6

% Fatos
animal(joao).
animal(maria).
animal(bidu).
animal(mingau).
animal(simba).
animal(rajah).

humano(joao).
humano(maria).

cachorro(bidu).
gato(mingau).
leao(simba).
tigre(rajah).

domestico(bidu).
domestico(mingau).

selvagem(simba).

som(bidu, latido).
som(mingau, miado).
som(simba, rugido).
som(rajah, rugido).

dono(joao, bidu).
dono(maria, mingau).
dono(maria, simba).


% Regras
eh_bipede(X) :-
    animal(X),humano(X).

eh_felino(X) :-
    gato(x); leao(X); tigre(X).

/** <examples>

?- animal(joao).
?- humano(X).
?- domestico(simba).
?- domestico(X).
?- som(X, latido).
?- dono(maria, X).

?- eh_bipede(mingau).
?- eh_bipede(maria).
?- eh_felino(rajah).
?- eh_felino(bidu).

% Conceitos
?- animal(maria), humano(maria).
?- animal(simba), domestico(simba).


*/
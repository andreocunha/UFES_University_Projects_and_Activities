% Andre Oliveira Cunha

%%%%% FATOS GERAIS %%%%%
remedio(ra).
remedio(rb).
remedio(rc).
remedio(rd).

sintoma(sx).
sintoma(sy).

trata(ra,sx).
trata(rb,sx).
trata(rc,sx).
trata(rd,sy).

%%%%% FATOS ESPECIFICOS DO PACIENTE %%%%%
paciente(p).
quadro(p,sx).
quadro(p,sy).

%%%%% FATOS SOBRE INTERACOES ENTRE MEDICAMENTOS %%%
interagem(ra,rb).
interagem(ra,rd).
interagem(rc,rd).

%%% REGRAS %%%%
%% recomenda medicacao de acordo com o(s) sintoma(s) do paciente 
recomendavel(P,R) :-
    quadro(P,Z),
    trata(R,Z).

%% verifica interacao entre medicacoes recomendaveis para um paciente
interacao(R1,R2) :-
    interagem(R1,Y),
    interagem(R2,Y);
    interagem(Y,R1),
    interagem(Y,R2);
    interagem(R1,R2).
    
verifica_interacao(P,R1,R2) :- 
	paciente(P),
    interagem(R1,R2).

/** <examples>

?- trata(ra, sx).
?- recomendavel(p, X).
?- interacao(ra,rd).
?- verifica_interacao(p,ra,rd).
*/

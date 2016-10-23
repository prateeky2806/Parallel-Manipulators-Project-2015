clear all;close all;clc;
prompt='Input the four lengths of Four bar Mechanisn as a vector [fixedLink , InputLink , Coupler , EndEffector]=  ' ;
A=input(prompt);
prompt='Input Omega= ' ;
Omega=input(prompt);

[ minIndex , minNum ] = getMin( A );
[ maxIndex , maxNum ] = getMax( A );
[Type] = checkType( minIndex , maxIndex , A );
FB_Animation(A,Omega,Type);

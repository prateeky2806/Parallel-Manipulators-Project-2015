clear all; close all;clc;
d=0.020;c=0.148;d1=0.020;c1=0.154;h=d1;
A=[];
B=[];
C=[];

for j=0:4:360*2
    
    r=0.04;
    xCircle=r*cos(j*3.14159/180);
    yCircle=r*sin(j*3.14159/180);
%top center co-ordinate in the frame of base center
xCTop=xCircle;
yCTop=yCircle;
zCTop=[h]; %height

%co-ordinates of the base plate in its own frame
xBase=[-c1/2, -c1/2-d/2, -d/2, d/2, c1/2+d/2, c1/2];
yBase=[-sqrt(3)*(c1+2*d)/6, -sqrt(3)*(c1-d)/6, sqrt(3)*(2*c1+d)/6, sqrt(3)*(2*c1+d)/6, -sqrt(3)*(c1-d)/6, -sqrt(3)*(c1+2*d)/6];
zBase=[0,0,0,0,0,0];
plate1=[xBase;yBase;zBase];

%co-ordinates of the top plate in its own frame
xTopFrame=[-d/2, -c/2-d/2, -c/2, +c/2,(c+d)/2, d/2];
yTopFrame=[-sqrt(3)*(2*c+d)/6, sqrt(3)*(c-d)/6, sqrt(3)*(c+2*d)/6, sqrt(3)*(c+2*d)/6, sqrt(3)*(c-d)/6, -sqrt(3)*(2*c+d)/6];
zTopFrame=[0,0,0,0,0,0];

%co-ordinates of the top plate in frame of the bottom plates center
xTop=xTopFrame+xCTop;
yTop=yTopFrame+yCTop;
zTop=zTopFrame+zCTop;

plate2=[xTop;yTop;zTop];

fill3(xBase,yBase,zBase,[1 0.6 0.78]); hold on; 
grid on; axis([-.15 .15 -.2 .2 0 .025]);
fill3(xTop,yTop,zTop,'c'); hold on;

for i=1:6
    plot3([xBase(i),xTop(i)],[yBase(i),yTop(i)],[zBase(i),zTop(i)],...
          'MarkerFaceColor',[1 0.694117665290833 0.39215686917305],...
          'MarkerEdgeColor',[0.749019622802734 0 0.749019622802734],...
          'Marker','o',...
          'LineWidth',3,...
          'Color',[0 1 0]);
          hold on;

xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');
end
    A=[A;xCTop];
    B=[B;yCTop];
    C=[C;zCTop];
    plot3(A,B,C,'r');
hold off
pause(0.025);
end
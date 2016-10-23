clc; clear all; close all;
d=0.020;c=0.148;d1=0.020;c1=0.154;h=d1;
xC=[0,0,h];

xBase=[-c1/2, -c1/2-d/2, -d/2, d/2, c1/2+d/2, c1/2];
yBase=[-sqrt(3)*(c1+2*d)/6, -sqrt(3)*(c1-d)/6, sqrt(3)*(2*c1+d)/6, sqrt(3)*(2*c1+d)/6, -sqrt(3)*(c1-d)/6, -sqrt(3)*(c1+2*d)/6];
zBase=[0,0,0,0,0,0];
plate1=[xBase;yBase;zBase];

xTop=[-d/2, -c/2-d/2, -c/2, +c/2,(c+d)/2, d/2];
yTop=[-sqrt(3)*(2*c+d)/6, sqrt(3)*(c-d)/6, sqrt(3)*(c+2*d)/6, sqrt(3)*(c+2*d)/6, sqrt(3)*(c-d)/6, -sqrt(3)*(2*c+d)/6];
zTop=[h,h,h,h,h,h];
plate2=[xTop;yTop;zTop];

fill3(xBase,yBase,zBase,[1 0.6 0.78]); hold on; 
grid on; axis([-.1 .1 -.1 .1 0 .025]);
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

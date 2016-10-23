%this function work well for double crank and crank rocker
function FB_Animation( A,Omega,Type)
% A is a vector of 4th dimension
if Type==1 || Type==3
    
    figure1 = figure('Color',[1 1 1]);
    set(gcf,'color',[1 1 1])
    axis([-5 15 -10 10]);
    axis equal
    
    for t=1:0.05:10
        th2=t*Omega;
        
        a=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)+2*A(1)*A(4)-2*A(4)*A(2)*cos(th2);
        b=4*A(2)*A(4)*sin(th2);
        c=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)-2*A(1)*A(4)+2*A(4)*A(2)*cos(th2);
        th4=2*atan((-b+sqrt(b*b-4*a*c))/(2*a));
        
        x0=10 ; y0=0;
        x1=10+A(2)*cos(th2); y1=A(2)*sin(th2);
        x2=10+A(1)+A(4)*cos(th4); y2=A(4)*sin(th4);
        x3=10+A(1); y3=0;
        cla
        hold on
        plot([x0 x1],[y0 y1],'LineWidth',2,'Color',[0 0.749019622802734 0.749019622802734]);
        plot([x1 x2],[y1 y2], 'MarkerFaceColor',[0 0.749019622802734 0.749019622802734],...
            'MarkerEdgeColor',[0.0784313753247261 0.168627455830574 0.549019634723663],...
            'MarkerSize',5,...
            'Marker','o',...
            'LineWidth',2,...
            'Color',[0.0588235296308994 0.874509811401367 0.470588237047195]);
        plot([x2 x3],[y2 y3],'LineWidth',2,...
            'Color',[0.0431372560560703 0.517647087574005 0.780392169952393]);
        plot([x0 x3],[y0 y3],...
            'MarkerFaceColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'MarkerEdgeColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'Marker','v',...
            'LineWidth',2,...
            'Color',[0.87058824300766 0.490196079015732 0]);
        pause(0.05);
        hold off
    end
end


if Type==4
    figure1 = figure('Color',[1 1 1]);
    set(gcf,'color',[1 1 1])
    axis([-5 15 -10 10]);
    axis equal
    
    for t=1:0.05:10
        th2=t*Omega;
        th4=th2;
        
        x0=10 ; y0=0;
        x1=10+A(2)*cos(th2); y1=A(2)*sin(th2);
        x2=10+A(1)+A(4)*cos(th4); y2=A(4)*sin(th4);
        x3=10+A(1); y3=0;
        cla
        hold on
        plot([x0 x1],[y0 y1],'LineWidth',2,'Color',[0 0.749019622802734 0.749019622802734]);
        plot([x1 x2],[y1 y2], 'MarkerFaceColor',[0 0.749019622802734 0.749019622802734],...
            'MarkerEdgeColor',[0.0784313753247261 0.168627455830574 0.549019634723663],...
            'MarkerSize',5,...
            'Marker','o',...
            'LineWidth',2,...
            'Color',[0.0588235296308994 0.874509811401367 0.470588237047195]);
        plot([x2 x3],[y2 y3],'LineWidth',2,...
            'Color',[0.0431372560560703 0.517647087574005 0.780392169952393]);
        plot([x0 x3],[y0 y3],...
            'MarkerFaceColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'MarkerEdgeColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'Marker','v',...
            'LineWidth',2,...
            'Color',[0.87058824300766 0.490196079015732 0]);
        pause(0.05);
        hold off
    end
end

if Type==5
    disp('I have not studied this case')
end

if Type==2
    figure1 = figure('Color',[1 1 1]);
    set(gcf,'color',[1 1 1])
    axis([-5 15 -10 10]);
    axis equal
    
    H=[];I=[];
    
    for t=0:0.05:10
        th2=t*Omega;
        
        a=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)+2*A(1)*A(4)-2*A(4)*A(2)*cos(th2);
        b=4*A(2)*A(4)*sin(th2);
        c=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)-2*A(1)*A(4)+2*A(4)*A(2)*cos(th2);
        th4=2*atan((-b+sqrt(b*b-4*a*c))/(2*a));
        
       
        x1=10+A(2)*cos(th2); y1=A(2)*sin(th2);
        x2=10+A(1)+A(4)*cos(th4); y2=A(4)*sin(th4);
       
        
        if A(3)== sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
            H=[H;th2];
            I=[I;th4];
        end
    end
    
    for th2=H(1,1):H(end,1)
      
        
        a=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)+2*A(1)*A(4)-2*A(4)*A(2)*cos(th2);
        b=4*A(2)*A(4)*sin(th2);
        c=A(3)*A(3)-A(1)*A(1)-A(4)*A(4)-A(2)*A(2)+2*A(1)*A(2)*cos(th2)-2*A(1)*A(4)+2*A(4)*A(2)*cos(th2);
        th4=2*atan((-b+sqrt(b*b-4*a*c))/(2*a));
        
        x0=10 ; y0=0;
        x1=10+A(2)*cos(th2); y1=A(2)*sin(th2);
        x2=10+A(1)+A(4)*cos(th4); y2=A(4)*sin(th4);
        x3=10+A(1); y3=0;
        cla
        hold on
        plot([x0 x1],[y0 y1],'LineWidth',2,'Color',[0 0.749019622802734 0.749019622802734]);
        plot([x1 x2],[y1 y2], 'MarkerFaceColor',[0 0.749019622802734 0.749019622802734],...
            'MarkerEdgeColor',[0.0784313753247261 0.168627455830574 0.549019634723663],...
            'MarkerSize',5,...
            'Marker','o',...
            'LineWidth',2,...
            'Color',[0.0588235296308994 0.874509811401367 0.470588237047195]);
        plot([x2 x3],[y2 y3],'LineWidth',2,...
            'Color',[0.0431372560560703 0.517647087574005 0.780392169952393]);
        plot([x0 x3],[y0 y3],...
            'MarkerFaceColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'MarkerEdgeColor',[0.24705882370472 0.24705882370472 0.24705882370472],...
            'Marker','v',...
            'LineWidth',2,...
            'Color',[0.87058824300766 0.490196079015732 0]);
        pause(0.005);
        hold off
    end
    disp('Work Going On , not completed')
end


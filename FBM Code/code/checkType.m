function [Type] = checkType( minIndex , maxIndex , A )
    Atotal=A(1)+A(2)+A(3)+A(4);
    if 2*(A(minIndex) + A(maxIndex)) < Atotal
        if minIndex==1
            disp('Crank-Crank')
            Type=1;
            %disp('Type-1 Enter "1" in FB_Animation Function to get desired animation')
        end
        if minIndex==3
            disp('Rocker-Rocker')
            Type=2; 
            %disp('Type-2 Enter "2" in FB_Animation Function to get desired animation')
        end
        if minIndex==2 || minIndex==4
            disp('Crank-Rocker')
            Type=3;
            %disp('Type-3 Enter "3" in FB_Animation Function to get desired animation')
        end
    end
    if 2*(A(minIndex) + A(maxIndex)) == Atotal
        if A(1)==A(3) && A(2)==A(4)
            disp('Parallel-Crank Four-Bar Linkage');
            Type=4;
            %disp('Type-4 Enter "4" in FB_Animation Function to get desired animation')
        end
    end
    if 2*(A(minIndex) + A(maxIndex)) > Atotal
        disp('Shortest + Longest > Sum of other two')
        Type=5;
        %disp('Type-5 Enter "5" in FB_Animation Function to get desired animation')
    end
end


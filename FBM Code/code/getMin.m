function [ minIndex , minNum ] = getMin( A )
    minNum=A(1); minIndex=0;
    for i=1:4
        if le(A(i),minNum)
            minNum=A(i);
            minIndex=i;
        end
    end
end


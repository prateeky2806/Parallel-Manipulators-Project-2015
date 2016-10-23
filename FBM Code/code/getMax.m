function [ maxIndex , maxNum ] = getMax( A )
    maxNum=A(1); maxIndex=0;
    for i=1:4
        if ge( A(i),maxNum)
            maxNum=A(i);
            maxIndex=i;
        end
    end
end
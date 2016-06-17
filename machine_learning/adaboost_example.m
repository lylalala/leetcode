clear;
clc;
x=[1 2 3 4  5  6  7 8 9 10];
y=[1 1 1 -1 -1 -1 1 1 1 -1];
w=ones(1,length(x)).*(1/length(x));
errorRate=1;
POS=[];
TIM=[];
ALP=[];
W=[];
W=[W;w];
while(errorRate>0.1)
    minErrorRatePos=1;
    time=1;
    for pos=1:1:11
        res=0;
        for i=1:1:10
            if(i<=pos)
                if(y(i)~=1)
                    res=res+w(i);
                end
            else
                if(y(i)~=-1)
                    res=res+w(i);
                end
            end
        end
        if(res<errorRate)
            minErrorRatePos=pos;
            time=1;
            errorRate=res;
        end
        res=0;
        for i=1:1:10
            if(i<=pos)
                if(y(i)~=-1)
                    res=res+w(i);
                end
            else
                if(y(i)~=1)
                    res=res+w(i);
                end
            end
        end
        if(res<errorRate)
            minErrorRatePos=pos;
            time=-1;
            errorRate=res;
        end
    end
    POS=[POS minErrorRatePos];
    TIM=[TIM time];
    alpha=0.5*log((1-errorRate)/errorRate);
    ALP=[ALP alpha];
    
    yy=[];
    for i=1:1:10
        if(i<=minErrorRatePos)
            yy=[yy time];
        else
            yy=[yy -time];
        end
    end
    Z=0;
    for i=1:1:10
        Z=Z+w(i)*exp(-alpha*yy(i)*y(i));
    end
    for i=1:1:10
        w(i)=w(i)*exp(-alpha*yy(i)*y(i))/Z;
    end
    W=[W;w];
end
clearvars alpha errorRate i minErrorRatePos pos res time w yy Z
save('adaboost_example.mat')
type mang = array [0 .. 100001] of Longint;
var a,b:mang; j,minn,i,n,k:longint;
begin
    read(n,k);
    for i:=1 to n do read(a[i]);
    for i:=2 to n do
    begin
        minn:=b[i-1]+abs(a[i-1]-a[i]);
        for j:=2 to k do
        begin
            if j>i-1 then break;
            if minn>b[i-j]+abs(a[i-j]-a[i]) then minn:=b[i-j]+abs(a[i-j]-a[i]);
        end;
        b[i]:=minn;
    end;
    write(b[n]);
end.
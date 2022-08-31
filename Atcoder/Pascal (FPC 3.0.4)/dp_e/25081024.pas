type mang = array[0 .. 101] of Longint;
type matran = array [0 .. 101, 0 .. 100001] of int64;
var m,n,i,j:longint; kq,t,k:int64; sol:matran; a,b:mang;
function min(a,b:int64):int64;
begin
    if a<b then exit(a) else exit(b);
end;
begin
    read(n,m);
    for i:=1 to n do begin read(a[i],b[i]); t:=t+b[i]; end;
    for i:=1 to n do
    begin
        for j:=0 to t do
        begin
            sol[i,j]:=sqr(sqr(sqr(10)))*sqr(sqr(10))*sqr(10);
        end;
    end;
    sol[1,0]:=0; sol[1,b[1]]:=a[1];
    for i:=2 to n do
    begin
        for j:=0 to t do
        begin
            sol[i,j]:=sol[i-1,j];
            if b[i]<=j then sol[i,j]:=min(sol[i,j],sol[i-1,j-b[i]]+a[i]);
        end;
    end;
    for i:=t downto 0 do
    begin
        for j:=1 to n do
        begin
            if sol[j,i]<=m then kq:=i;
        end;
        if kq<>0 then break;
    end;
    write(kq);
end.
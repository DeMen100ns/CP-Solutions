type mang = array [0 .. 100001] of int64;
var sol:mang; i,n,k,j:longint; w,v,lastsol:int64;
function max(a,b,c:int64):int64;
var maxx:int64;
begin
    maxx:=a; if maxx<b then maxx:=b; if maxx<c then maxx:=c; exit(maxx);
end;
begin
    read(n,k);
    for i:=1 to n do
    begin
        read(w,v);
        for j:=k downto w do
        begin
            sol[j]:=max(sol[j],sol[j-w]+v,-1);
        end;
    end;
    lastsol:=0;
    for i:=0 to k do
    begin
        lastsol:=max(lastsol,sol[i],-1);
    end;
    write(lastsol);
end.
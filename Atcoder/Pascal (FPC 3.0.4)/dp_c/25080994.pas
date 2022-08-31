type mang = array [0 .. 100001] of Longint;
var a,b,c,d,e,f:mang; i,n:longint;
function max(a,b,c:longint):longint;
var maxx:longint;
begin
    maxx:=a; if maxx<b then maxx:=b; if maxx<c then maxx:=c; exit(maxx);
end;
begin
    read(n);
    for i:=1 to n do read(a[i],b[i],c[i]);
    d[1]:=a[1]; e[1]:=b[1]; f[1]:=c[1];
    for i:=2 to n do
    begin
        d[i]:=a[i]+max(e[i-1],f[i-1],0);
        e[i]:=b[i]+max(d[i-1],f[i-1],0);
        f[i]:=c[i]+max(d[i-1],e[i-1],0);
    end;
    write(max(d[n],e[n],f[n]));
end.
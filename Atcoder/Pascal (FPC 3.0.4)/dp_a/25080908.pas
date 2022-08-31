type mang = array [0 .. 100001] of Longint;
var a,b:mang; i,n:longint;
function min(a,b:longint):longint;
begin
    if a<b then exit(a) else exit(b);
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=2 to n do
    begin
        if i>2 then b[i]:=min(b[i-1]+abs(a[i]-a[i-1]),b[i-2]+abs(a[i]-a[i-2]))
        else b[i]:=abs(a[i]-a[i-1]);
    end;
    write(b[n]);
end.
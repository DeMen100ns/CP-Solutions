const mot097=1000000007;
type matran = array [0 .. 1001, 0 .. 1001] of Int64;
var a:matran; m,n,i,j:longint; s:ansistring;
begin
    read(m); readln(n);
    for i:=1 to m do
    begin
        readln(s);
        for j:=1 to length(s) do if s[j]='#' then a[i,j]:=-1;
    end;
    if a[1,1]<>-1 then a[1,1]:=1;
    for i:=1 to m do
    begin
        for j:=1 to n do
        begin
            if (i>1) or (j>1) then
            begin
                if a[i,j]>-1 then
                begin
                    a[i,j]:=((a[i-1,j] mod mot097)+(a[i,j-1] mod mot097)) mod mot097;
                    if a[i-1,j]=-1 then inc(a[i,j]);
                    if a[i,j-1]=-1 then inc(a[i,j]);
                end;
            end;
        end;
    end;
    if a[m,n]=-1 then inc(a[m,n]);
    write(a[m,n]);
end.

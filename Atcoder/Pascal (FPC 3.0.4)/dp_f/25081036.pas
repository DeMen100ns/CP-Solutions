const saiso=0.00000000001;
      mot097=1000000007;
type mang = array [0 .. 1000000] of int64;
     matran = array [0 .. 3001, 0 .. 3001] of int64;
     mangb = array [0 .. 100001] of Boolean;
     mangc = array [0 .. 100001] of Char;
     mangchuoi = array [0 .. 100001] of String;
     bignum = ansistring;
var n:int64; s,s2,s3:ansistring; i,j:longint; sol:matran;
function max(a,b:longint):longint;
begin
    if a>b then exit(a) else exit(b);
end;
BEGIN
    readln(s); read(s2);
    sol[0,0]:=0;
    for i:=1 to length(s) do
    begin
        for j:=1 to length(s2) do
        begin
            if s[i]=s2[j] then sol[i,j]:=sol[i-1,j-1]+1
            else sol[i,j]:=max(sol[i-1,j],sol[i,j-1]);
        end;
    end;
    while sol[i,j]>0 do
    begin
        if sol[i-1,j]=sol[i,j] then
        begin
            dec(i);
        end
        else if sol[i,j-1]=sol[i,j] then
             begin
                 dec(j);
             end
             else
             begin
                 s3:=s[i]+s3;
                 dec(i); dec(j);
             end;
    end;
    write(s3);
END.
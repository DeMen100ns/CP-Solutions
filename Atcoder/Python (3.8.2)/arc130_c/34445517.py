def evaluate(A, B):
  # A + B の桁和を求める
  A = list(map(int, A))
  B = list(map(int, B))
  ANS = 0
  carry = 0
  while A or B or carry:
    a = A.pop() if A else 0
    b = B.pop() if B else 0
    x, carry = a + b + carry, 0
    if x >= 10:
      x, carry = x - 10, 1
    ANS += x
  return ANS

def solve(a0, CNT_A, CNT_B):
  # A の 1 の位として a0 を使う場合
  X = []
  Y = []
  def add(a, b, n=None):
    nonlocal X, Y
    if n is None:
      n = min(CNT_A[a], CNT_B[b])
    CNT_A[a] -= n; X += [a] * n
    CNT_B[b] -= n; Y += [b] * n
    
  # 可能なら 10 以上を作る
  for b in range(10 - a0, 10):
    if CNT_A[a0] and CNT_B[b]:
      add(a0, b, 1)
      break
  # 9 以上を作っていく
  for a in range(10):
    for b in range(9 - a, 10):
      add(a, b)
  # 降順に追加
  for x in reversed(range(10)):
    X += [x] * CNT_A[x]
    Y += [x] * CNT_B[x]
  S = "".join(map(str, X[::-1]))
  T = "".join(map(str, Y[::-1]))
  return (S, T)

A = [int(x) for x in input()]
B = [int(x) for x in input()]
CNT_A = [0] * 10
CNT_B = [0] * 10
for x in A:
  CNT_A[x] += 1
for x in B:
  CNT_B[x] += 1

best = None, "", ""
for a0 in range(1, 10):
  a, b = solve(a0, CNT_A.copy(), CNT_B.copy())
  x = evaluate(a, b)
  if best[0] is None or best[0] > x:
    best = (x, a, b)
print(*best[1:], sep='\n')
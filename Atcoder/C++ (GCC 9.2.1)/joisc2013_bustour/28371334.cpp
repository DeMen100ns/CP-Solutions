/*
Author : DeMen100ns (a.k.a Vo Khac Trieu self-destruct)
School : VNU-HCM High school for the Gifted
*/

#include <bits/stdc++.h>

using namespace std;
 
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
 
struct Bus {
	int L, T, N;
	Bus(int L, int T, int N) : L(L), T(T), N(N) {};
};
 
struct Point {
	int X, Y, N;
	bool Flag;
	Point(int X, int Y, bool Flag, int N) : X(X), Y(Y), Flag(Flag), N(N) {};
};
 
int main() {
	int W, H, SX, SY, GX, GY, N;
	cin >> W >> H >> SX >> SY >> GX >> GY >> N;
	SX--, SY--, GX--, GY--;
	swap(SX, SY), swap(GX, GY);
	static vector<Bus> Adj[1000][1000][4];
	for (int i = 0; i < N; i++) {
		int X1, Y1, X2, Y2, T;
		cin >> X1 >> Y1 >> X2 >> Y2 >> T;
		X1--, Y1--, X2--, Y2--;
		swap(X1, Y1), swap(X2, Y2);
		int Loop = (X2 - X1 + Y2 - Y1) * 2;
		int NT = (Loop - T) % Loop;
		for (int j = Y1; j < Y2; j++) {
			Adj[X1][j][0].push_back(Bus(Loop, NT, i));
			NT++;
			if (NT == Loop) NT = 0;
		}
		for (int j = X1; j < X2; j++) {
			Adj[j][Y2][1].push_back(Bus(Loop, NT, i));
			NT++;
			if (NT == Loop) NT = 0;
		}
		for (int j = Y2; j > Y1; j--) {
			Adj[X2][j][2].push_back(Bus(Loop, NT, i));
			NT++;
			if (NT == Loop) NT = 0;
		}
		for (int j = X2; j > X1; j--) {
			Adj[j][Y1][3].push_back(Bus(Loop, NT, i));
			NT++;
			if (NT == Loop) NT = 0;
		}
	}
	static int Dist[1000][1000][2] = {};
	int MAX = 5000000;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) Dist[i][j][0] = Dist[i][j][1] = MAX;
	}
	static vector<Point> BFS[5000];
	Dist[SX][SY][1] = 0;
	BFS[0].push_back(Point(SX, SY, 1, -1));
	for (int p = 0; p < 1000; p++) {
		for (int q = 0; q < 5000; q++) {
			int i = p * 5000 + q;
			for (Point P : BFS[q]) {
				if (Dist[P.X][P.Y][P.Flag] < i) continue;
				for (int j = 0; j < 4; j++) {
					for (Bus NP : Adj[P.X][P.Y][j]) {
						if (P.Flag == 0) {
							if (P.N == NP.N) {
								int NX = P.X + dx[j], NY = P.Y + dy[j], NT = i + 1;
								if (Dist[NX][NY][0] > NT&& MAX > NT) {
									Dist[NX][NY][0] = NT;
									BFS[NT % 5000].push_back(Point(NX, NY, 0, P.N));
								}
							}
						}
						else {
							if (P.N != NP.N) {
								int NX = P.X + dx[j], NY = P.Y + dy[j], NT = NP.L * ((i + NP.L - NP.T - 1) / NP.L) + NP.T + 1;
								if (Dist[NX][NY][0] > NT&& MAX > NT) {
									Dist[NX][NY][0] = NT;
									BFS[NT % 5000].push_back(Point(NX, NY, 0, NP.N));
								}
							}
						}
					}
				}
				if (P.Flag == 0) {
					if (Dist[P.X][P.Y][1] > i + 1 && MAX > i + 1) {
						Dist[P.X][P.Y][1] = i + 1;
						BFS[(i + 1) % 5000].push_back(Point(P.X, P.Y, 1, P.N));
					}
				}
			}
			while (!BFS[q].empty()) BFS[q].pop_back();
		}
	}
	cout << Dist[GX][GY][0] << endl;
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

//bead
struct bead {
	int y;
	int x;
	char col;
	int direction;	//0:up, 1:left, 2:down, 3:right
};

//global variables
pair<int, int> goal;
int n, m;		//field size
int ans = 0;	//answer value
bead r, b;		//red, blue balls
char board[11][11];	//game field
int min_path[11][11];	//dp
bool visited[11][11];	//visited field
int dirY[] = { -1, 0, 1, 0 };	//Y direction
int dirX[] = { 0, -1, 0, 1 };	//X direction

//prototypes
bool movePossible();
void makeGame();
void playGame();

void playGame() {
	bool moveFlag = true;
	while (moveFlag) {

	}
}

bool isGoal(bead color) {
	if (color.y == goal.first && color.x == goal.second) {
		if (color.col == 'r') {
			return true;
		}
		else if (color.col == 'b') {
			ans = -1;
			return true;
		}
	}
	return false;
}

bool movePossible(bead color) {
	int dy = color.y + dirY[color.direction];
	int dx = color.x + dirX[color.direction];
	if (board[dy][dx] == '#') 
		return false;
	if (color.col == 'r' && board[dy][dx] == 'B') 
		return false;
	else if (color.col == 'b' && board[dy][dx] == 'R') 
		return false;
	return true;
}

//initialize game
void makeGame() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				r.y = i;
				r.x = j;
				r.col = 'r';
			}
			else if (board[i][j] == 'B') {
				b.y = i;
				b.x = j;
				b.col = 'b';
			}
			else if (board[i][j] == 'O') {
				goal.first = i;
				goal.second = j;
			}
		}
	}
}

/*		main		*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	makeGame();

	return 0;

}

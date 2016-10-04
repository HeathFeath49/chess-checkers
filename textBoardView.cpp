#include <iostream>
#include <vector>

using namespace std;


//CLASSES
//PieceDrawer contains method to drawPiece onto board 
class PieceDrawer {
	public:
		PieceDrawer();
		void drawPiece(int pieceType); //must be passed piece types from subclasses 
};

class ChessBoardPD:public PieceDrawer{
	public:
		ChessBoardPD();
		void drawPiece(int pieceType);
};

class CheckerBoardPD:public PieceDrawer{
	public:
		CheckerBoardPD();
		void drawPiece(int pieceType);
};

struct Rectangle {
	int rectWidth;
	int rectHeight;
	Rectangle(int width,int height):rectWidth(width),rectHeight(height){};
};

// TextBoardView maintains all piece locations and draws pieces accordingly
class TextBoardView {
	public:
		TextBoardView(int rows, int cols,Rectangle rect,PieceDrawer pd); // constructor
		void placePiece(int row, int col, int pieceType);
		void removePiece(int row, int col, int pieceType);
		void draw();
		Rectangle myRectangle;
		
	private:
		/*void drawPiece(int pieceType, int width, int height, int rowNum);*/
		vector<vector<int>> myPieceTypes;  // myPieceTypes[row] is vector of ints
		                                   // representing piece types
		int myRows;
		int myCols;
		PieceDrawer myPd;
		// other data to include?
};



//TEXTBOARDVIEW
//TextBoardView Class Function Bodies
TextBoardView::TextBoardView(int rows, int cols,Rectangle rect,PieceDrawer pd) {
	// Constructor: intialize private data variables as necessary
	vector<int> temp;
	
	myRows = rows;
	myCols = cols;
	myPd = pd;
	myRectangle = rect;
	
	for(int r = 0; r < myRows; r++) {
		for(int c = 0; c < myCols; c++) {
			temp.push_back((c % 2) + 7);
		}
		myPieceTypes.push_back(temp);
		temp.clear();
	}
}

void TextBoardView::draw() {
	int cellHeight = myRectangle.rectHeight; // should be calculated from myHeight
	for(int r = 0; r < myRows; r++) {
		for(int h = 0; h < cellHeight; h++) {
			// need to draw each row of cell
			// draw top border
			for(int i = 0; i < myCols; i++) {
				cout << " -";
			}
			cout << " " << endl;
			for(int c = 0; c < myCols; c++) {
				cout << "|"; // draw left border
				// width/height need to be recalculated (not 1 by 1)
				myPd.drawPiece(myPieceTypes[r][c]);
			}
			cout << "|" << endl; // draw outer right border
		}
	}
	
	// draw bottom border
	for(int i = 0; i < myCols; i++) {
		cout << " -";
	}
	cout << " " << endl;
}

void TextBoardView::removePiece(int row, int col, int pieceType) {
	// TODO
}

void TextBoardView::placePiece(int row, int col, int pieceType) {
	// TODO
}


//PIECEDRAWER
//PieceDrawer Class Function Bodies
PieceDrawer::PieceDrawer(){
	cout<<"Piece Drawer Created!";
}

void PieceDrawer::drawPiece(int pieceType) {
	// private helper method to draw individual rows of piece graphics:
	//     prints row number rowNum of piece pieceType given;
	//     piece graphic occupies rectangle of width rows & height columns;
	//     don't include borders
	
	// CHESS
	
	if(pieceType == 1) {
		cout << "W";
	} 
	else if(pieceType == 2) {
		cout << "B";
	} 
	else if(pieceType == 3) {
		// draw row of bishop
	}
	else if(pieceType == 4) {
		// draw row of rook
	}
	else if(pieceType == 5) {
		// draw row of queen
	}
	else if(pieceType == 6) {
		// draw row of king
	}
	
	// CHECKERS / CONNECT FOUR
	else if(pieceType == 7) {
		// draw row of red checker
		cout << "R";
	}
	else if(pieceType == 8) {
		// draw row of black checker
		cout << "B";
	}
	
	else {
		// draw empty square row (spaces?)
		cout << pieceType;
	}
	
	// OTHER GAMES
}


//CHESSBOARD
ChessBoardPD::ChessBoardPD(){
	/*cout<<"chess board pd created";*/
}

void ChessBoardPD::drawPiece(int pieceType){
	cout << "chess board draw piece called";
	if(pieceType == 7) {
		cout << "W";
	} 
	else if(pieceType == 8) {
		cout << "H";
	}
}

/*void ChessBoardPD::printMessage(char msg){
	cout<< msg;
}
*/

//CHECKERBOARD
CheckerBoardPD::CheckerBoardPD(){
	
}

void CheckerBoardPD::drawPiece(int pieceType){
	if(pieceType == 7) {
		// draw row of red checker
		cout << "R";
	}
	else if(pieceType == 8) {
		// draw row of black checker
		cout << "B";
	}
}


int main() {
	//ChessBoardPD chPD;
    //TextBoardView tv(7, 7,chPD);
    //tv.draw();
    
    return 0;
}

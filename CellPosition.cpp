#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	if (v<5 && v>=0) {
		vCell = v;
		return true;
	}
	else
		return false;

	                                                               // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	if (h >=0 && h < 11) {                                 ///: Implement this function as described in the .h file (don't forget the validation)
		hCell = h;
		return true;
	}
	else
		return false;                               // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (((HCell() >= 0) && (HCell() <= 10)) && ((VCell() <= 4) && (VCell() >= 0))) {
		return true;
	}
	else return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int cellnum=0;
	for (int i = 4; i >=0 ; i--)																									// Note:
	{
		for (int j = 0; j <11; j++)
		{
			if ((i == cellPosition.vCell) && (j == cellPosition.hCell)) {
				cellnum++;
				return cellnum;

			}
			else
				cellnum++;
		}																							// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	}																							// just define an integer that represents cell number and calculate it using the passed cellPosition then return it																									///: Implement this function as described in the .h file																				// this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int cellnum = 0;
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 11; j++) {
			if (cellnum + 1 == cellNum) {
				position.SetHCell(j);
				position.SetVCell(i);
				return position;
			}
			else
				cellnum++;
		}
	}											/// : Implement this function as described in the .h file																				// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function																				//       I mean: position.SetVCell(...) and position.SetHCell(...) then return i
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	if (addedNum >= 0) {
		if (direction == RIGHT || direction == LEFT) {
			if (direction == RIGHT) {
				if (addedNum + HCell() <= 10) {
					SetHCell(addedNum + HCell());
				}
			}
			else {
				if (HCell() - addedNum >= 0) {
					SetHCell(HCell() - addedNum);
				}
			}
		}
		else if (direction == UP || direction == DOWN) {
			if (direction == UP) {
				if (VCell() - addedNum >= 0) {
					SetVCell(VCell() - addedNum);
				}
			}
			else {
				if (addedNum + VCell() <= 4) {
					SetVCell(addedNum + VCell());
				}
			}

		}

	}
}
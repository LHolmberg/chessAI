#include "Queen.h"

bool Queen::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int dy = abs(newPos.second - mapgrid[n][k].second);
    int dx = abs(newPos.first - mapgrid[n][k].first);

    //any diagonal and straight up/down/sidetoside = OK
    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    if(DidMeet(GetTravelpath(std::make_pair(gridX,gridY), newPos), pieces) == false) {
        for(int i = 0; i < 8; i++) {
            if(newPos.second == mapgrid[n][k].second || newPos.first == mapgrid[n][k].first
                || newPos.second == mapgrid[i][k].second && dx == dy
                    || newPos.second == mapgrid[i][k].second && dx == dy
                        || newPos.first == mapgrid[n][i].first && dx == dy
                            || newPos.first == mapgrid[n][i].first && dx == dy)
                return true;

        }
        return false;
    } else 
        return false;
}

std::string Queen::name() const {
    return "Queen";
}
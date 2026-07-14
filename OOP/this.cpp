#include <iostream>
#include <string>
using string = std::string;
class win{
    int score, match, p_id;
    string rank;
    public:
        win(int score, int match, int p_id){
            // can't x = x
            //instead we use this keyword ,here 'this->x' is class member and 'x' is 
            //argument
            //or like win* w = this , then w.x = x
            this->score = score;
            this->match = match;
            this->p_id = p_id;
        }
        void setRank(){
            if (score >= 1000) {
                rank = "DIAMOND";
            } else if (score >= 500) {
                rank = "PLATINUM";
            } else if (score >= 100) {
                rank = "GOLD";
            } else if (score >= 50) {
                rank = "SILVER";
            } else if (score >= 10) {
                rank = "BRONZE";
            } else {
                rank = "UNRANKED";
            }
        }
        const string& getRank() const {
            return rank;
        }
};
int main(){
    win w{190, 2, 58940};
    w.setRank();
    std::cout << w.getRank() << std::endl;
    return 0;
}
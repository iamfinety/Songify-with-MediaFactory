
#include "Criteria.h"

ostream& operator<<(ostream& ost, Criteria& c){
    ost<< endl;
    c.print(ost);
    return ost;
}
A_Criteria::A_Criteria(const string& artist){
    this->artist = artist;
}
bool A_Criteria::matches(const Song& song){
    return (this->artist.compare(song.getArtist()) == 0);
}
void A_Criteria::print(ostream& ost) const{
    ost<<"This criteria will match a song by artist: "<<artist<<endl;
}
C_Criteria::C_Criteria(const string& category){
    this->category = category;
}
bool C_Criteria::matches(const Song& song){
    return (this->category.compare(song.getCategory()) == 0);
}
void C_Criteria::print(ostream& ost) const{
    ost<<"This criteria will match a song by category: "<<category<<endl;
}
AorC_Criteria::AorC_Criteria(const string& artist, const string& category):A_Criteria(artist), C_Criteria(category){

}
bool AorC_Criteria::matches(const Song& song){
    return(A_Criteria::matches(song) || C_Criteria::matches(song));
}
void AorC_Criteria::print(ostream& ost) const{
    A_Criteria::print(ost);
    C_Criteria::print(ost);
}
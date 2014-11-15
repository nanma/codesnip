#include <string>

using std::string;

class StreetParking {
 public:
  int freeParks(string street);
};

int StreetParking::freeParks(string street) {
  bool r1 = false, r2 = false, r3 = false, r4 = false,
       r5 = false, r6 = false, r7 = true;
  int cnt = 0;
  for (int i = 0; i < street.size(); ++i) {
    r1 = (street[i] != 'D') ? true : false;
    r2 = street[i] != 'B' ? true : false;
    if (i + 1 == street.size())
      r3 = true;
    else
      r3 = street[i+1] != 'B' ? true : false;
    if (i + 2 >= street.size())
      r4 = true;
    else
      r4 = street[i+2] != 'B' ? true : false;
    r5 = street[i] != 'S' ? true : false;
    if (i + 1 == street.size())
      r6 = true;
    else
      r6 = street[i+1] != 'S' ? true : false;
    if (i == 0)
      r7 = true;
    else
      r7 = street[i-1] != 'S' ? true : false;
    if (r1 && r2 && r3 && r4 && r5 && r6 && r7)
      cnt++;
  }
  return cnt;
}

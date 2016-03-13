#include "DribbblePalette.h"

void DribbblePalette::urlResponse(ofHttpResponse & _res) {
  if (res.status==200 && res.request.name == "async_req") {
    res = _res;
  } else {
    cout << res.status << " " << res.error << endl;
  }
}

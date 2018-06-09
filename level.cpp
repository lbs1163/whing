#include <level.hpp>
#define K1 0.01
#define K2 0.1

namespace whing {

  /*
       Whing Exp = (a + r) * k1 + (fl_a + fl_r) * k2
          fl_a = sum of flaps by article
          fl_r = sum of flaps by reply
          a = number of articles
          r = number of replies
          k1 = weight for flaps, 0.01
          k2 = weight for the num of articles and replies, 0.1
  */

  bool level::update_total_exp(){

      require_auth( _self );

      if (false /* condition */) {
        return false;
      }
      uint64_t fl_a = article.get_total_flaps_by_owner( this.account );
      uint64_t fl_b = reply.get_total_flaps_by_owner( this.account );
      // uint64_t a = number of articles
      // uint64_t r = number of replies

      this.total_exp =  (a + r) * K1 + (fl_a + fl_r) * K2;

    return true;
  }

  // Getters
  uint64_t level::get_total_exp()
  {
    return this.total_exp;
  }

  uint32_t level::get_level()
  {
    return ( this.total_exp / EXP_THRESHOLD );

  }

}
// end of namespace whing

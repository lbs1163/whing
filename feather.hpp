#pragma once
#include <eosiolib/eosio.hpp>
#define EXP 10000

namespace whing {

  struct site_info {
    std::string  url;
    uint64_t     level = 0;
  };

  class level {
    std::vector<site_info>;
    uint64_t primary_key(account_name acc) const { return owner; }


  }

  class flap {
    uint64_t numofflaps

  }

  class exp{

  }

}
// end of namespace whing

#pragma once
#include <eosiolib/eosio.hpp>
#define EXP_THRESHOLD 100 // Interval of experience to get level
#define RATIO 0.1

namespace whing {

  struct website {
    std::string  url = "none";
    uint64_t     level = 0;
    uint64_t     exp = 0;
  };

  // levels can be calculated by certain threshold, EXP_THRESHOLD
  class level {
    std::vector<website> website_list;
    uint64_t primary_key(account_name acc) const { return website_list; }

    
  }

}
// end of namespace whing

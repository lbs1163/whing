#pragma once
#include <eosiolib/eosio.hpp>
#include "account_manager.hpp"
#define EXP_THRESHOLD 100 // Interval of experience to get level

namespace whing {

  class level {
    uint32_t num_of_boards;

    std::vector<board> board_list;
    uint64_t primary_key(account_name acc) const { return board_list; }

  public:

    level():num_of_boards(0); // seed account needed

    // Setters
    bool exp_up( account_name acc, uint32_t board_id, uint32_t increment ); // including level calculation
    bool set_board( account_name acc, std::string _url, bool _isOwner );

/*  EDIT FUNCTIONS ARE NOT COVERED AT HACKATHON */
//  bool edit_url(  account_name acc, std::string _url, bool _isOwner );

    // Getters
    std::vector<board> get_boards( account_name acc );
            // specific getters would be set up at service side

  }
}
// end of namespace whing

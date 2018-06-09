#pragma once
#include <eosiolib/eosio.hpp>
#define EXP_THRESHOLD 100 // Interval of experience to get level

namespace whing {

  struct board {
    uint32_t     board_id; // starts from 0
    std::string  url;
    uint64_t     exp;
    uint64_t     level; // level = exp/EXP_THRESHOLD
    bool isOwner; // true = OWNED, false = JOINED

    board(uint32_t _id, std::string _url, bool _isOwner)
          : board_id(_id), url(_url), exp(0), level(0), isOwner(_isOwner) {}

  };

  class level {
    uint32_t num_of_boards;

    std::vector<board> board_list;
    uint64_t primary_key(account_name acc) const { return board_list; }

  public:

    level():num_of_boards(0); // seed account needed

    // Setters
    bool exp_up( account_name acc, uint32_t board_id ); // including level calculation
    bool set_board( account_name acc, std::string _url, bool _isOwner );

// NOT COVERED AT HACKATHON
//    bool edit_url(  account_name acc, std::string _url, bool _isOwner );
//    bool add_new_acc(); // to be moved onto service

    // Getters
    std::vector<board> get_boards( account_name acc );
            // specific getters would be set up at service side

  }
}
// end of namespace whing

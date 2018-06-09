#pragma once
#include <eosiolib/eosio.hpp>
#include "account_manager.hpp"
#define EXP_THRESHOLD 100 // Interval of experience to get level

namespace whing {

  class level {
    account_name account;
    uint32_t board_id; // pseudo-random
    uint64_t total_exp; // Level = EXP / EXP_THRESHOLD

    uint32_t num_of_replies;
    uint32_t num_of_articles;

    uint64_t primary_key() const { return board_id; }
    uint64_t secondary_key() const { return account; }

  public:
    // Setters
    bool update_total_exp();

    // Getters
    uint64_t get_total_exp();
    uint32_t get_level();

  }
}
// end of namespace whing

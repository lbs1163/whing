#pragma once

#include <eosiolib/multi_index.hpp>
#include <whing/level.hpp>
#include <whing/energy.hpp>
#include <whing/flap.hpp>
namespace whing {
   class service {
      public:




      private:
         struct board {
            uint32_t       board_id; // pseudo-random
            std::string    url;
            uint64_t       exp;
            uint32_t       level; // user's level, exp/EXP_THRESHOLD
            account_name   owner;
            uint64_t       num_of_articles;


            uint64_t primary_key() const { return board_id; }
            uint64_t secondary_key() const { return owner; }

         };

      };

} // end of namespace whing

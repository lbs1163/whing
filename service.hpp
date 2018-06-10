#pragma once

#include <eosiolib/eosio.hpp>
#include <whing/level.hpp>
#include <whing/energy.hpp>
#include <whing/flap.hpp>
#include <whing/board_db.hpp>
#include <whing/article_db.hpp>
#include <whing/reply_db.hpp>

namespace whing {
   class service : public eosio::contract {
      public:
         using contract::contract;

         /// @abi action 
         void add_board(account_name owner, std::string url);

         /// @abi action
         void add_article(uint32_t board_id, account_name owner, std::string url, std::string title, std::string data, std::string img_url);

         /// @abi action
         void add_reply(uint32_t article_id, account_name owner, std::string data);

/*         
         get_all_data_by_board_id(uint32_t board_id);

         get_joined_boards();

         get_owned_boards();
*/
   };


} 

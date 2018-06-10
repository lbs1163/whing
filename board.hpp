#pragma once

#include <eosiolib/eosio.hpp>

namespace whing {
   board get_board_by_id(uint32_t id);

   void add_board(account_name owner, std::string url);
   
   struct board {
      uint32_t       board_id; 
      account_name   owner;
      std::string    url;


      uint64_t primary_key()const { return board_id; }
      account_name get_owner()const { return owner; }

      EOSLIB_SERIALIZE( board, (board_id)(owner)(url) ) 
   };

   typedef eosio::multi_index<N(boards), board,
      indexed_by<N(by_owner), const_mem_fun<board, account_name, &board::get_owner>>,
      > boards;

} 

#pragma once

#include <eosiolib/eosio.hpp>

namespace whing {
   struct article {
      uint32_t       article_id; // pseudo-random
      uint32_t       board_id;
      account_name   owner;
      std::string    url;
      uint64_t       created;
      std::string    title;
      std::string    data;
      std::string    img_url;
      uint64_t       num_flaps;
      uint64_t       num_replies;

      uint32_t     primary_key()const { return article_id; }
      uint32_t     get_board_id()const { return board_id; }
      account_name get_owner()const { return owner; }

      EOSLIB_SERIALIZE( article, (article_id)(board_id)(owner)(url)(created)(title)(data)(img_url)(num_flaps)(num_replies) )
   };

   struct owned_articles {
      uint64_t    total_claps = 0;
      uint64_t    counts = 0;
      uint64_t    total_replies = 0;
   };
   
   article get_article_by_id(uint32_t id);
   owned_articles get_owned_articles(account_name owner);
   vector<article> get_articles_by_board_id(uint32_t board_id);

   typedef eosio::multi_index<N(articles), article,
      indexed_by<N(by_board_id), const_mem_fun<article, uint32_t, &article::get_board_id>>,
      indexed_by<N(by_owner), const_mem_fun<article, account_name, &article::get_owner>>,
      > articles;

};


#pragma once

#include <eosiolib/multi_index.hpp>

namespace whing {
   class article_manager {
      public:
         article get_article_by_id(uint32_t id);
         
         owned_infos get_owned_infos(account_name owner);
 
         struct owned_infos {
            uint64_t    total_claps = 0;
            uint64_t    counts = 0;
            uint64_t    total_replies = 0;
         };

      private:
         struct article {
            uint32_t       article_id; // pseudo-random
            account_name   owner;
            uint32_t       board_id;
            std::string    url;
            uint64_t       created_time;
            std::string    title;
            std::string    data;
            std::string    img_url;
            uint64_t       num_flaps;
            uint64_t       num_replies;

            uint32_t primary_key() const { return article_id; }
            account_name get_owner() const { return owner; }

         };


         
         typedef eosio::multi_index<N(articles), article,
            indexed_by<N(byowner), const_mem_fun<article, account_name, &article::get_owner>>,
            > articles;

};


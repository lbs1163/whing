#pragma once

#include <eosiolib/multi_index.hpp>

namespace whing {
   class article {
      public:

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
            uint32_t get_owner() const { return owner; }

         };

         
         typedef eosio::multi_index<N(articles), article,
            indexed_by<N(by_owner), const_mem_fun<owner, account_name, &article::get_owner>>,
            > articles;

};


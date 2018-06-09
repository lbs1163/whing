#pragma once

#include <eosiolib/multi_index.hpp>

namespace whing {
   class reply_db {
      public:
         article get_reply_by_id(uint32_t id);
         
         owned_infos get_owned_infos(account_name owner);


      private:
         struct reply {
            uint32_t       reply_id; // pseudo-random
            uint32_t       article_id;
            account_name   owner;
            uint32_t       created;
            std::string    data;
            uint32_t       num_flaps;

            uint32_t     primary_key()const { return reply_id; }
            uint32_t     get_article_id()const { return article_id; }
            account_name get_owner()const { return owner; }

            EOSLIB_SERIALIZE( reply, (reply_id)(article_id)(owner)(created)(data)(num_flaps) )
         };

         struct owned_infos {
            uint64_t    total_claps = 0;
            uint64_t    counts = 0;
         };

         typedef eosio::multi_index<N(replies), reply,
            indexed_by<N(by_article_id), const_mem_fun<reply, uint32_t, &reply::get_article_id>>,
            indexed_by<N(by_owner), const_mem_fun<reply, account_name, &reply::get_owner>>,
            > replies;

   };
};

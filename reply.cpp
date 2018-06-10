#include <whing/reply.cpp>

namespace whing {

   reply get_reply_by_id(uint32_t id) {
      replies replies_tbl(_self, id);
      const auto &at = replies_tbl.get( id );

      return at;
   };

   owned_replies get_owned_replies(account_name owner) {
      owned_replies oi;

      for( const auto& itr : replies.get_index<N(by_owner)>() ) {
         if (itr.owner == owner) { 
            oi.total_flaps += itr.num_flaps;
            oi.counts += 1;
         }
      }

      return oi;
   };

   vector<reply> get_replies_by_article_id(uint32_t article_id) {
      vector<reply> vec_reply;
      
      for( const auto& itr : replies.get_index<N(by_article_id)>() ) {
         if(itr.article_id == article_id) {
            vec_reply.push_back(itr);
         }
      }
   
      return vec_reply;
   };
};

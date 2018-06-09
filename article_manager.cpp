
#include <whing/article_manager.cpp>

namespace whing {

   article article_manager::get_article_by_id(uint32_t id) {
      articles articles_tbl(_self, id);
      const auto &at = articles_tbl.get( id );

      return at;
   };

   owned_infos article_manager::get_owned_infos(account_name owner) {
      auto article_index = articles.get_index<N(byowner)>();
      auto itr = article_index.lower_bound(owner);

      owned_infos oi;

      for( const auto& itr : articles.get_index<N(byowner)>() ) {
         if (itr.owner == owner) { 
            oi.total_flaps += itr.num_flaps;
            oi.counts += 1;
            oi.total_replies += num_replies; 
         }
      }

      return oa;
   };

};

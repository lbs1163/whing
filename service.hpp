#pragma once
#include <level.hpp>

namespace whing {


  struct board {

    uint32_t       board_id; // starts from 0
    std::string    url;
    uint64_t       exp;
    uint64_t       level; // user's level, exp/EXP_THRESHOLD
    account_name   owner;

    uint64_t       num_of_articles;

    board(uint32_t _id, std::string _url, account_name _owner)
          : board_id(_id), url(_url), exp(0), level(0), owner(_owner), num_of_articles(0) {}

    std::vector<article> article_list;
    uint64_t primary_key(account_name acc) const { return article_list; }

  };

  struct article {

    uint32_t       article_id; // starts from 0
    std::string    url;
    uint64_t       exp;
    account_name   owner;

    uint64_t       created_time;
    std::string    title;
    std::string    data;
    std::string    img_url;

    uint64_t       num_of_flaps;
    uint64_t       num_of_replies;

    article(uint32_t _id, std::string _url, account_name owner,
            std::string _title, std::string _data, std::string _img_url,
            uint64_t created_time)
          : article_id(_id), url(_url), exp(0), level(0), owner(_owner),
            title(_title), data(_data), img_url(_img_url),
            num_of_flaps(0), num_of_replies(0) {}

    std::vector<reply> reply_list;
    uint64_t primary_key(account_name acc) const { return reply_list; }

    // 	serialized(reply_id…)
  };

  struct reply {

    uint64_t       reply_id; // starts from 0
    uint64_t       article_id;
    std::string    article_author;
    std::string    url;
    account_name   owner;

    uint64_t       exp;
    uint64_t       created_time;

    std::string    data;

    uint64_t       num_of_flaps;

    reply(uint32_t _id, uint32_t _id2, std::string _article_author, std::string _url,
          uint64_t created_time, account_name owner, std::string _data)
          : reply_id(_id), replied_article_id(_id2), article_author(_article_author), url(_url),
            owner(_owner), exp(0), created_time(_created_time), data(_data), num_of_flaps(0) {}

    //	serialized (reply_id…)

  };


} // end of namespace whing


//
// API 명세
//
// JSON 응답은 표시된 정보들은 필수적으로 필요하고 다른 데이터가 추가적으로 들어와도 상관 없습니다.(ID 등이 serialize 등으로 자동적으로 들어와도 됨) JSON 구조 바꾸는게 편하면 알려주세요
//
// # getArticles(boardId, articleNum)
// boardId에 해당하는 보드에서 최신순으로 게시글을 articleNum 개수만큼 (부족하면 전부) JSON으로 가져옴.
// ex) 정상 작동시
// {
//   articles: [
//     author: {
//         username: "Beomsu Lim",
//         level: 7 (그 사이트 레벨로 주세요)
//     },
//     title: "asdfasdf",
//     text: "dsfsedvisjefowefklsdjf",
//     published: "(포맷 정해서 알려주세요)",
//     dollars: 13221(글이 번 돈),
//     votes: 42,
//     comments: 67 (댓글 구현 안할꺼면 그냥 상수로 넣을께요)
//   ],
// }
// 에러 발생시
// { errors: "Couldn't get articles from blockchain: ERRNO XXX" }
//
// # postArticle(boardId, postingKey, title, text)
// boardId에 해당하는 보드에 새로운 글을 작성함. title과 text가 제목과 내용이고 postingKey는 블록체인 인증을 위한 패스워드. 성공 여부를 JSON으로 가져옴.
//
// ex) 성공시
// { success: true }
// 실패시
// { success: false, errors: "asdf"}
//
// # flapArticle(articleId, postingKey)
// articleId에 해당하는 글에 postingKey에 해당하는 유저가 flap함. 성공 여부를 JSON으로 가져옴.
//
// ex) 성공시
// { success: true }
// 실패시
// { success: false, errors: "asdf"}

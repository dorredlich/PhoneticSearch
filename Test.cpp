#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of f and b") {
    string text = "fun friend but big body for me";
    CHECK(find(text, "fun") == string("fun"));
    CHECK(find(text, "friend") == string("friend"));
    CHECK(find(text, "briend") == string("friend"));
    CHECK(find(text, "but") == string("but"));
    CHECK(find(text, "fut") == string("but"));
    CHECK(find(text, "big") == string("big"));
    CHECK(find(text, "fig") == string("big"));
    CHECK(find(text, "body") == string("body"));
    CHECK(find(text, "fody") == string("body"));
    CHECK(find(text, "bor") == string("for"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "the word is wondeful with wine";
    CHECK(find(text, "word") == string("word"));
    CHECK(find(text, "vord") == string("word"));
    CHECK(find(text, "wondeful") == string("wondeful"));
    CHECK(find(text, "vondeful") == string("wondeful"));
    CHECK(find(text, "with") == string("with"));
    CHECK(find(text, "vith") == string("with"));
    CHECK(find(text, "wine") == string("wine"));
    CHECK(find(text, "vine") == string("wine"));
}

TEST_CASE("Test replacement of upper-case and lower-case") {
    string text = "fun but scary";
    CHECK(find(text, "fun") == string("fun"));
    CHECK(find(text, "FuT") == string("fun"));
    CHECK(find(text, "fUn") == string("fun"));
    CHECK(find(text, "ScArY") == string("scary"));
    CHECK(find(text, "scaRy") == string("scary"));
    CHECK(find(text, "scARy") == string("scary"));
    CHECK(find(text, "sCaRy") == string("scary"));
    CHECK(find(text, "But") == string("but"));
    CHECK(find(text, "bUt") == string("but"));
    CHECK(find(text, "BUT") == string("but"));
    CHECK(find(text, "BuT") == string("but"));
}

TEST_CASE("Test replacement of k and q") {
    string text = "know xxx yyy";
    CHECK(find(text, "know") == string("know"));
    CHECK(find(text, "qnow") == string("know"));
}

TEST_CASE("Test replacement of k and c") {
    string text = "xxx yyy knife";
    CHECK(find(text, "knife") == string("knife"));
    CHECK(find(text, "cnife") == string("knife"));
}

TEST_CASE("Test replacement of c and q") {
    string text = "car quit and close quickly";
    CHECK(find(text, "car") == string("car"));
    CHECK(find(text, "qar") == string("car"));
    CHECK(find(text, "quit") == string("quit"));
    CHECK(find(text, "cuit") == string("quit"));
    CHECK(find(text, "close") == string("close"));
    CHECK(find(text, "qlose") == string("close"));
    CHECK(find(text, "quickly") == string("quickly"));
    CHECK(find(text, "cuickly") == string("quickly"));
    CHECK(find(text, "quiqkly") == string("quickly"));
    CHECK(find(text, "cuiqkly") == string("quickly"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "so see is zero zone";
    CHECK(find(text, "so") == string("so"));
    CHECK(find(text, "zo") == string("so"));
    CHECK(find(text, "see") == string("see"));
    CHECK(find(text, "zee") == string("see"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "iz") == string("is"));
    CHECK(find(text, "zero") == string("zero"));
    CHECK(find(text, "sero") == string("zero"));
    CHECK(find(text, "zone") == string("zone"));
    CHECK(find(text, "sone") == string("zone"));
}


TEST_CASE("Test replacement of g and j") {
    string text = "join to good jump game ";
    CHECK(find(text, "join") == string("join"));
    CHECK(find(text, "goin") == string("join"));
    CHECK(find(text, "good") == string("good"));
    CHECK(find(text, "jood") == string("good"));
    CHECK(find(text, "jump") == string("jump"));
    CHECK(find(text, "gump") == string("jump"));
    CHECK(find(text, "game") == string("game"));
    CHECK(find(text, "jame") == string("game"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "dont delete the table ";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "tond") == string("dont"));
    CHECK(find(text, "delete") == string("delete"));
    CHECK(find(text, "delede") == string("delete"));
    CHECK(find(text, "telete") == string("delete"));
    CHECK(find(text, "telede") == string("delete"));
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "dhe") == string("the"));
    CHECK(find(text, "table") == string("table"));
    CHECK(find(text, "bable") == string("table"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "open or close but usually dont";
    CHECK(find(text, "open") == string("open"));
    CHECK(find(text, "or") == string("or"));
    CHECK(find(text, "ur") == string("or"));
    CHECK(find(text, "close") == string("close"));
    CHECK(find(text, "cluse") == string("close"));
    CHECK(find(text, "but") == string("but"));
    CHECK(find(text, "bot") == string("but"));
    CHECK(find(text, "usually") == string("usually"));
    CHECK(find(text, "osoally") == string("usually"));
    CHECK(find(text, "osually") == string("usually"));
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "dunt") == string("dont"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "i will yell yes inside";
    CHECK(find(text, "i") == string("i"));
    CHECK(find(text, "y") == string("i"));
    CHECK(find(text, "will") == string("will"));
    CHECK(find(text, "wyll") == string("will"));
    CHECK(find(text, "yell") == string("yell"));
    CHECK(find(text, "iell") == string("yell"));
    CHECK(find(text, "yes") == string("yes"));
    CHECK(find(text, "ies") == string("yes"));
    CHECK(find(text, "inside") == string("inside"));
    CHECK(find(text, "ynsyde") == string("inside"));
    CHECK(find(text, "insyde") == string("inside"));
}
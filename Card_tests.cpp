#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}

TEST(test_get_rank) {
    Card two_spades = Card();
    ASSERT_EQUAL(two_spades.get_rank(), TWO);
}

TEST(get_card_1) {
    Card c(JACK, SPADES);
    ASSERT_EQUAL(c.get_rank(), JACK);
    ASSERT_EQUAL(c.get_suit(), SPADES);
}

TEST(get_card_2) {
    Card c(NINE, DIAMONDS);
    ASSERT_EQUAL(c.get_rank(), NINE);
    ASSERT_EQUAL(c.get_suit(), DIAMONDS);
}

TEST(get_suit_1) {
    Card c(JACK, SPADES);
    ASSERT_EQUAL(c.get_suit(CLUBS), CLUBS);
}

TEST(get_suit_2) {
    Card c(JACK, DIAMONDS);
    ASSERT_EQUAL(c.get_suit(HEARTS), HEARTS);
}

TEST(get_suit_3) {
    Card c(TEN, HEARTS);
    ASSERT_EQUAL(c.get_suit(DIAMONDS), HEARTS);
}

TEST(face_or_ace_1) {
    Card c(TEN, SPADES);
    ASSERT_EQUAL(c.is_face_or_ace(), false);
}

TEST(face_or_ace_2) {
    Card c(JACK, DIAMONDS);
    ASSERT_EQUAL(c.is_face_or_ace(), true);
}

TEST(face_or_ace_3) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(c.is_face_or_ace(), true);
}

TEST(right_bower_1) {
    Card c(JACK, DIAMONDS);
    ASSERT_EQUAL(c.is_right_bower(DIAMONDS), true);
}

TEST(right_bower_2) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(c.is_right_bower(HEARTS), false);
}

TEST(left_bower_1) {
    Card c(JACK, HEARTS);
    ASSERT_EQUAL(c.is_left_bower(DIAMONDS), true);
}

TEST(left_bower_2) {
    Card c(JACK, SPADES);
    ASSERT_EQUAL(c.is_left_bower(SPADES), false);
}

TEST(trump_1) {
    Card c(NINE, DIAMONDS);
    ASSERT_EQUAL(c.is_trump(DIAMONDS), true);
}

TEST(trump_2) {
    Card c(TEN, SPADES);
    ASSERT_EQUAL(c.is_trump(HEARTS), false);
}

TEST(trump_3) {
    Card c(JACK, CLUBS);
    ASSERT_EQUAL(c.is_trump(SPADES), true);
}

TEST(smaller_than_1) {
    Card c1(ACE, HEARTS);
    Card c2(TEN, DIAMONDS);
    ASSERT_EQUAL(c1<c2, false);
}

TEST(smaller_than_2) {
    Card c1(ACE, HEARTS);
    Card c2(ACE, DIAMONDS);
    ASSERT_EQUAL(c1<c2, true);
}

TEST(smaller_or_equal_1) {
    Card c1(KING, SPADES);
    Card c2(QUEEN, CLUBS);
    ASSERT_EQUAL(c1<=c2, false);
}

TEST(smaller_or_equal_2) {
    Card c1(QUEEN, HEARTS);
    Card c2(QUEEN, CLUBS);
    ASSERT_EQUAL(c1<=c2, true);
}

TEST(bigger_than_1) {
    Card c1(TEN, HEARTS);
    Card c2(TEN, SPADES);
    ASSERT_EQUAL(c1>c2, true);
}

TEST(bigger_than_2) {
    Card c1(QUEEN, HEARTS);
    Card c2(TEN, DIAMONDS);
    ASSERT_EQUAL(c1>c2, true);
}

TEST(not_equals_to_1) {
    Card c1(QUEEN, DIAMONDS);
    Card c2(TEN, HEARTS);
    ASSERT_EQUAL(c1!=c2, true);
}

TEST(suit_next_1) {
    ASSERT_EQUAL(Suit_next(SPADES), CLUBS);
    ASSERT_EQUAL(Suit_next(DIAMONDS), HEARTS);
}

TEST(card_less_1) {
    Card c1(JACK, DIAMONDS);
    Card c2(ACE, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, DIAMONDS), false);
}

TEST(card_less_2) {
    Card c1(JACK, CLUBS);
    Card c2(QUEEN, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, SPADES), false);
}

TEST(card_less_3) {
    Card c1(JACK, DIAMONDS);
    Card c2(JACK, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, HEARTS), true);
}

TEST(card_less_4) {
    Card c1(TEN, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, DIAMONDS), false);
}

TEST(card_less_5) {
    Card c1(TEN, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, SPADES), true);
}

TEST(card_less_6) {
    Card c1(QUEEN, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    ASSERT_EQUAL(Card_less(c1, c2, SPADES), false);
}

TEST(card_less_7) {
    Card c1(TEN, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    Card ld(JACK, DIAMONDS);
    ASSERT_EQUAL(Card_less(c1, c2, ld, SPADES), false);
}

TEST(card_less_8) {
    Card c1(TEN, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    Card ld(JACK, DIAMONDS);
    ASSERT_EQUAL(Card_less(c1, c2, ld, HEARTS), true);
}

TEST(card_less_9) {
    Card c1(NINE, DIAMONDS);
    Card c2(QUEEN, HEARTS);
    Card ld(JACK, SPADES);
    ASSERT_EQUAL(Card_less(c1, c2, ld, CLUBS), true);
}



// Add more test cases here

TEST_MAIN()

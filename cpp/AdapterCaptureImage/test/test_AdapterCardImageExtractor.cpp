#include "gtest/gtest.h"
#include "AdapterCardImageExtractor.h"
#include <memory>

TEST(loadAndGetImageContainerTest, ImageContainerNotEmpty) {
  std::unique_ptr<AdapterCardImageExtractor> instance_cardImageExtractor = std::make_unique<AdapterCardImageExtractor>();
  std::string filename{"./cpp/AdapterCardImageExtractor/images/step8_1447109970617_tcm1488-264382.jpg"};
  instance_cardImageExtractor->load_image(filename);
  auto image_container=instance_cardImageExtractor->get_image_container();
  EXPECT_EQ(1,image_container.size());
  EXPECT_EQ(false,image_container[0].empty());
}

TEST(extractCardPositiveTest, CheckCardTypeAndValue) {
  std::unique_ptr<AdapterCardImageExtractor> instance_cardImageExtractor = std::make_unique<AdapterCardImageExtractor>();
  std::string filename{"./cpp/AdapterCardImageExtractor/images/step8_1447109970617_tcm1488-264382.jpg"};
  instance_cardImageExtractor->load_image(filename);
  auto instance_unordered_map=instance_cardImageExtractor->extract_card(0);
  EXPECT_EQ(1,instance_unordered_map.size());
  auto itr= instance_unordered_map.cbegin();
  EXPECT_EQ("Hearts",itr->first);
  EXPECT_EQ(12,itr->second);
}

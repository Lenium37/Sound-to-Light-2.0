//
// Created by Jan on 06.06.2019.
//

#ifndef RASPITOLIGHT_SRC_CORE_LIB_LIGHTSHOW_LIGHT_SHOW_GENERATOR_H_
#define RASPITOLIGHT_SRC_CORE_LIB_LIGHTSHOW_LIGHT_SHOW_GENERATOR_H_

#include <memory>
#include "lightshow/analysis_result.h"
#include "lightshow/lightshow_fixture.h"
#include "lightshow/generated_light_show.h"
#include "lightshow/lightshow.h"
#include <song.h>
#include <fixturemanager/fixture.h>

struct color_values {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

class LightshowGenerator {
 public:
  LightshowGenerator();
	~LightshowGenerator();
  std::shared_ptr<Lightshow> generate(int resolution, Song *song, std::list<Fixture> fixtures);
 private:
  float fade_duration = 1;
  std::shared_ptr<AnalysisResult> analysis_result;
  void generate_color_fades(std::shared_ptr<Lightshow> lightshow_from_analysis, LightshowFixture& fix, std::vector<std::string>& colors);
  void generate_beat_color_changes(std::shared_ptr<Lightshow> lightshow_from_analysis, LightshowFixture& fix, std::vector<std::string>& colors);
  void set_soft_color_changes(std::shared_ptr<Lightshow> lightshow_from_analysis, LightshowFixture& fix, std::vector<color_change> color_changes, float fade_duration);
  void set_hard_color_changes(std::shared_ptr<Lightshow> lightshow_from_analysis, LightshowFixture &fix, std::vector<color_change> color_changes);
  std::vector<time_value_int> calculate_single_fade(std::shared_ptr<Lightshow> lightshow_from_analysis, float fade_duration, int c_old, int c_new);
  void set_color_for_fixed_time(LightshowFixture& fix, std::string& color, float begin, float end);
  void set_color_of_fixture_during_song(std::shared_ptr<Lightshow> lightshow_from_analysis, LightshowFixture& fix, std::initializer_list<std::string> a_args);
  color_values color_to_rgb(std::string color);
  //std::vector<LightshowFixture> fixtures;
};

#endif //RASPITOLIGHT_SRC_CORE_LIB_LIGHTSHOW_LIGHT_SHOW_GENERATOR_H_

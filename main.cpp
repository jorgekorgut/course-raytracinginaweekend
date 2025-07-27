#include "camera.h"
#include "hittable_list.h"
#include "material.h"
#include "rtweekend.h"
#include "sphere.h"
#include <fstream>
#include <memory>

int main(int argc, char *argv[]) {
  // Check if image name is provided
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <output_image_name>\n";
    return 1;
  }

  // Check if image name already exists
  std::string image_name = argv[1];
  if (std::ifstream(image_name)) {
    std::cerr << "Error: Image file '" << image_name << "' already exists.\n";
    return 1;
  }
  hittable_list world;
  auto R = std::cos(pi / 4);

  auto material_left = make_shared<lambertian>(color(0, 0, 1));
  auto material_right = make_shared<lambertian>(color(1, 0, 0));

  world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
  world.add(make_shared<sphere>(point3(R, 0, -1), R, material_right));

  camera cam;
  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 400;
  cam.samples_per_pixel = 100;
  cam.max_depth = 50;
  cam.vfov = 90;

  cam.render(world, image_name);
}
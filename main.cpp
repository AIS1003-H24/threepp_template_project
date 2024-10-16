#include "threepp/threepp.hpp"

#include "threepp/extras/imgui/ImguiContext.hpp"

using namespace threepp;

namespace {

    auto createMesh() {
        const auto geometry = BoxGeometry::create();
        const auto material = MeshBasicMaterial::create();
        material->color = Color::green;

        auto mesh = Mesh::create(geometry, material);

        return mesh;
    }

}

int main() {

    Canvas canvas;
    GLRenderer renderer{canvas.size()};

    PerspectiveCamera camera(60, canvas.aspect(), 0.1, 1000);
    camera.position.z = 5;

    Scene scene;
    scene.background = Color::aliceblue;

    auto mesh = createMesh();
    scene.add(mesh);

    bool& meshVisible = mesh->visible;

    ImguiFunctionalContext ui(canvas.windowPtr(), [&meshVisible] {
        ImGui::SetNextWindowPos({}, 0, {});
               ImGui::SetNextWindowSize({230, 0}, 0);
               ImGui::Begin("Mesh settings");
               ImGui::Checkbox("Visible", &meshVisible);

               ImGui::End();
    });
    // ui.makeDpiAware(); // to increase imgui size on high DPI screens

    Clock clock;
    float rotationSpeed = 0.5f;
    canvas.animate([&] {
        const auto dt = clock.getDelta();

        mesh->rotation.y += rotationSpeed * dt;

        renderer.render(scene, camera);
        ui.render();
    });
}

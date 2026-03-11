 #include <iostream>
 #include <Core/Application.hpp>

 int main(int argc, char* argv[])
 {
      try
      {
            Engine::Application app;
            app.run();
      }
      catch(const std::exception& e)
      {
            std::cout << e.what() << std::endl;
      }
 }
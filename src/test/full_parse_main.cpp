#include "full_parse_test_common.hpp"
#include <rapidxml_ns/rapidxml_ns_utils.hpp>
#include <boost/timer/timer.hpp>

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " <svg file name>\n";
    return 1;
  }

  try
  {
    rapidxml_ns::file<> xml_file(argv[1]);

    rapidxml_ns::xml_document<> doc;
    {
      std::cout << "Parsing XML ";
      boost::timer::auto_cpu_timer xml_timer;
      doc.parse<rapidxml_ns::parse_no_string_terminators>(xml_file.data());  
    }

    std::cout << "Parsing SVG ";
    boost::timer::auto_cpu_timer svg_timer;
    parse(doc.first_node());
  }
  catch (std::exception const & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
#include <ifstream>
#include <string>
#include <set>
using std::endl;
using std::cout;
using std::cin;

class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream &is) {
		strore_file(is);
		build_map(is);
	}
	std::set<line_no> run_query(const std::string&) const;
	std::string text_line(line_no) const;
private:
	void store_file(std::ifstream&);
	void build_map();
	std::vector<std::string> lines_of_text;
	std::map< std::string, std::set<line_no> > word_map;
};

void TextQuery::store_file(ifstream &is)
{

}


void print_result(const set<TextQuery::line_no>)& locs, const string& sought, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs "
		 << size << " "
		 << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it = locs.begin();
	for( ; it != locs.end(); ++it)
	{
		cout << "\t(line )"
			 << (*it) + 1 << ") "
			 << file.text_line(*it) << endl;
	}
}


int main(int argc, char **argv)
{
	ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);
	while(true){
		cout << "enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if(!cin || s == "q")
			break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}


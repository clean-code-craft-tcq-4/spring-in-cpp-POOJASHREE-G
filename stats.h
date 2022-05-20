#include <vector>

namespace Statistics {
    
    class Stats
    {
    public:
        float average;
        float max;
        float min;
	    
	Stats()
	{
		average = NAN;
		max = NAN;
		min = NAN;
	}
    };
    
    Stats ComputeStatistics(const std::vector<float>& );    
}


class IAlerter
{
public:
	virtual void Update() = 0; 
};

class EmailAlert : public IAlerter
{
public:
	bool emailSent;

	EmailAlert()
		 : emailSent(false) { }

	void Update()
	{
		emailSent = true;
	}

};

class LEDAlert : public IAlerter
{
public:
	bool ledGlows;

	LEDAlert()
		: ledGlows(false) { }


	void Update()
	{
		ledGlows = true;
	}

};

class StatsAlerter
{
public:

	std::vector<IAlerter*> Alrts;

        float maxthres;

	StatsAlerter(const float maxthresold, std::vector<IAlerter*> alerts)
	{
		maxthres = maxthresold;
		Alrts = alerts;
	}

	void checkAndAlert(const std::vector<float>& vect)
	{
		auto ComputedStats = Statistics::ComputeStatistics(vect);
		if ( ComputedStats.max > maxthres )
		{
			for (int i = 0; i < Alrts.size(); ++i)
			{
				Alrts[i]->Update();
			}
		}
	};
};

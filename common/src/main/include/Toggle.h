#pragma once

namespace curtinfrc {
  enum ToggleEvent {
    ONFALL,
    ONRISE,
    ONCHANGE
  };

  class Toggle {
  public:
    Toggle(ToggleEvent mode = ToggleEvent::ONRISE);
    Toggle(ToggleEvent mode, bool initState);

    bool tick(bool val);

    bool getTriggered();

  private:
    ToggleEvent _mode;
    bool _triggered;
    bool _lstate;
  };
} // ns curtinfrc

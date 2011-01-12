

#overload for Orocos::OutputPort so they can be connected to 
#widgets
module Orocos
  class OutputPort
    alias :org_connect_to :connect_to
    alias :org_disconnect_all :disconnect_all
    alias :org_disconnect_from :disconnect_from
    def connect_to(widget=nil, options = Hash.new,&block)
      if widget.is_a?(Hash)
        options = widget
        widget = nil
      end
      if widget.is_a?(Qt::Widget)||!widget
        QGui.connections << Vizkit::OQConnection.new(self, options,widget,&block)
      else
        return org_connect_to widget,options
      end
      self
    end

    def disconnect_all
      QGui.disconnect_from(self)
      org_disconnect_all
    end

    def disconnect_from(widget)
      if widget.is_a?(Qt::Widget)
        QGui.disconnect_from(widget)
      else
        org_disconnect_from(widget)
      end
    end
  end
end